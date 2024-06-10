# 11 10 02 01 20 11 20 01 02 01 02

from IPython.display import clear_output
boat_side = "Right"
missionary_on_right = 3
cannibals_on_right = 3
missionary_on_left = 0
cannibals_on_left = 0

print("🙂"*missionary_on_left, "😈"*cannibals_on_left, end='')
print("  |_______🛶|  ", end='')
print("🙂"*missionary_on_right, "😈"*cannibals_on_right)

while True:
    missionary = int(input("Enter number of Missionary in boat on "+ boat_side + ":"))
    cannibals = int(input("Enter number of Cannibals in boat on " + boat_side + ":"))

    if (missionary+cannibals) != 1 and (missionary+cannibals) != 2:
        print("Invalid move")
        continue

    if boat_side == "Right":
        if missionary > missionary_on_right or cannibals > cannibals_on_right:
            print("Invalid move")
            continue

        missionary_on_right -= missionary
        cannibals_on_right -= cannibals
        missionary_on_left += missionary
        cannibals_on_left += cannibals

        boat_side = "Left"
        clear_output()
        print("\n🙂"*missionary_on_left, "😈"*cannibals_on_left, end='')
        print("  |🛶_______|  ", end='')
        print("🙂"*missionary_on_right, "😈"*cannibals_on_right)

    else:
        if missionary > missionary_on_left or cannibals > cannibals_on_left:
            print("Invalid move")
            continue

        missionary_on_right += missionary
        cannibals_on_right += cannibals
        missionary_on_left -= missionary
        cannibals_on_left -= cannibals

        boat_side = "Right"
        clear_output()
        print("\n🙂"*missionary_on_left, "😈"*cannibals_on_left, end='')
        print("  |_______🛶|  ", end='')
        print("🙂"*missionary_on_right, "😈"*cannibals_on_right)

    if (missionary_on_right != 0 and missionary_on_right < cannibals_on_right) or (missionary_on_left != 0 and missionary_on_left < cannibals_on_left):
        print("YOU LOSE")
        break

    if missionary_on_left == 3 and cannibals_on_left == 3:
        print("YOU WIN")
        break
print("GAME OVER")