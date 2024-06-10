import pdb
from random import shuffle

class State:
    def __init__(self):
        self.properties = self.generateStates()

    def __eq__(self, other):
        return self.properties == other.properties

    def generateStates(self):
        properties = set()

        POSITIONS = [0, 1, 2]
        ELEMENTS = ["monkey", "banana", "box"]

        for el in ELEMENTS:
            for pos in POSITIONS:
                properties.add(el + "At" + str(pos))

        properties.add('monkeyLevelUp')
        properties.add('monkeyLevelDown')
        properties.add('haveBanana')
        return properties

    def setProperties(self, properties):
        self.properties = properties

    def __str__(self):
        return str(self.properties)
    def __repr__(self):
        return str(self.properties)


class Operation:
    def __init__(self, name):
        self.name = name
        self.PC = set()
        self.A = set()
        self.E = set()

    def __str__(self):
        return "{}".format(self.name)

    def __eq__(self, other):
        return self.name == other.name

    def __hash__(self):
        return hash(self.name)

    def canApply(self, state):
        return self.PC.intersection(state.properties) == self.PC

    def apply(self, state):
        s = State()
        properties = set()
        if self.canApply(state):
            properties = state.properties.union(self.A)
            properties = properties.difference(self.E)
        s.setProperties(properties)
        return s

    def show(self):
        print(self.name)
        print("PC: {}".format(self.PC))
        print("A: {}".format(self.A))
        print("E: {}".format(self.E))

class Move(Operation):
    def __init__(self, object, x, y):
        self.name = "Move{}({},{})".format(object, x, y)
        self.object = object
        self.x = x
        self.y = y
        self.PC = self.getPreconditions()
        self.A = self.getA()
        self.E = self.getE()

    def getPreconditions(self):
        p = set()
        p.add(self.object + "At" + str(self.x))
        if self.object == 'monkey':
            p.add('monkeyLevelDown')
        return p

    def __repr__(self):
        return Operation.__str__(self)

    def getA(self):
        p = set()
        p.add(self.object + "At" + str(self.y))
        return p

    def getE(self):
        p = set()
        p.add(self.object + "At" + str(self.x))
        return p

class PushBox(Operation):
    def __init__(self, x, y):
        self.name = "PushBox({},{})".format(x, y)
        self.x = x
        self.y = y
        self.PC = self.getPreconditions()
        self.A = self.getA()
        self.E = self.getE()

    def __repr__(self):
        return Operation.__str__(self)

    def getPreconditions(self):
        p = set()
        p.add("boxAt" + str(self.x))
        p.add("monkeyAt" + str(self.x))
        p.add("monkeyLevelDown")
        return p

    def getA(self):
        p = set()
        p.add("boxAt" + str(self.y))
        p.add("monkeyAt" + str(self.y))
        return p

    def getE(self):
        p = set()
        p.add("boxAt" + str(self.x))
        p.add("monkeyAt" + str(self.x))
        return p

class ClimbBox(Operation):
    def __init__(self, x, updown):
        self.name = "ClimbBox{}(at {})".format(updown, x)
        self.x = x
        self.updown = updown
        self.PC = self.getPreconditions()
        self.A = self.getA()
        self.E = self.getE()

    def __repr__(self):
        return Operation.__str__(self)

    def getPreconditions(self):
        p = set()
        p.add("boxAt" + str(self.x))
        p.add("monkeyAt" + str(self.x))
        if self.updown == 'Up':
            p.add("monkeyLevelDown")
        else:
            p.add("monkeyLevelUpAt{}".format(self.x))
        return p

    def getA(self):
        p = set()
        if self.updown == 'Up':
            p.add("monkeyLevelUpAt{}".format(self.x))
        else:
            p.add("monkeyLevelDown".format(self.x))
            p.add("monkeyAt{}".format(self.x))
        return p

    def getE(self):
        p = set()
        if self.updown == 'Up':
            p.add("monkeyLevelDown")
        else:
            p.add("monkeyLevelUpAt{}".format(self.x))
        return p

class HaveBanana(Operation):
    def __init__(self, x):
        self.name = "GetBanana(at {})".format(x)
        self.x = x
        self.PC = self.getPreconditions()
        self.A = self.getA()
        self.E = self.getE()

    def __repr__(self):
        return Operation.__str__(self)

    def getPreconditions(self):
        p = set()
        p.add("boxAt" + str(self.x))
        p.add("monkeyAt" + str(self.x))
        p.add("bananaAt" + str(self.x))
        p.add("monkeyLevelUpAt{}".format(self.x))
        return p

    def getA(self):
        p = set()
        p.add("haveBanana")
        return p

    def getE(self):
        p = set()
        return p

def generateOperations(initial):
    operations = list()
    s = State()
    properties = s.generateStates()

    elements = ['banana', 'monkey', 'box']
    movement = ['Up', 'Down']
    positions = [0, 1, 2]

    for x in positions:
        for y in positions:
            if x!=y:
                operations.append(Move('monkey', x, y))
                operations.append(PushBox(x,y))

        for direction in movement:
            operations.append(ClimbBox(x, direction))

    for item in list(initial.properties):
        if 'banana' in item:
            operations.append(HaveBanana(item.split('At')[1]))
    return operations


def selectOperation(cs, gs):
    return list(set(filter(lambda x: len(x.A.intersection(gs)) > 0, generateOperations(cs))))

def isFinalState(state, goal):
    return state.properties.intersection(goal.properties) == goal.properties

def STRIPSiter(state, goal):
    plan = []
    stack = list(goal.properties)
    while len(stack) > 0:
        target = stack[0]
        if type(target) in [ClimbBox, HaveBanana, PushBox, Move]:
            state = target.apply(state)
            plan.append(target)
            stack.remove(target)
        elif target in state.properties:
            stack.remove(target)
        elif type(target) == str:
            operations = list(selectOperation(state, {target}))
            if len(operations) > 0:
                if 'monkeyAt' in target:
                    operations = list(filter(lambda x: type(x) == Move, operations))
                shuffle(operations)
                operation = operations[0]
                stack = [operation] + stack
                stack = list(operation.PC) + stack
            else:
                stack = []
                plan = False
    return plan

initial = State()
initial.setProperties({"monkeyAt0", "bananaAt1", "boxAt2", "monkeyLevelDown"})

goal = State()
goal.setProperties({'haveBanana'})

print("Initial state: \n---------\n{}\n".format(initial))
print("Goal state: \n---------\n{}\n".format(goal))
print("STRIPS START\n==============")
plan = STRIPSiter(initial, goal)
if plan:
    print("\nDone! Final plan: \n{}".format(plan))
else:
    print("STRIPS did not find solution")