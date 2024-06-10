from matplotlib import pyplot as plt

x_roll = [80, 70, 60, 10, 20, 50, 40, 90, 100, 30]
y_marks = [50, 60, 30, 40, 100, 10, 90, 80, 50, 30]
y_scholarship = [100, 120, 100, 250, 200, 150, 100, 120, 100, 200]

sorted_X = sorted(x_roll)
sorted_Y = sorted(y_marks)
sorted_S = sorted(y_scholarship)

plt.plot(sorted_X, sorted_Y, 'ob--', label="Marks")
plt.plot(sorted_X, sorted_S, 'or--', label='Scholarship')
plt.title("Roll No - Marks Relationship Graph")
plt.xlabel("Roll Numbers")
plt.ylabel("Marks Achieved")
plt.legend()

for i, (x, y) in enumerate(zip(sorted_X, sorted_Y)):
    plt.annotate(f'({x}, {y})', (x, y), textcoords="offset points", xytext=(0,10), ha='center')

for i, (x, y) in enumerate(zip(sorted_X, sorted_S)):
    plt.annotate(f'({x}, {y})', (x, y), textcoords="offset points", xytext=(0,10), ha='center')

plt.show()