import turtle
import math
import time

def josephus_circular_permutation():
    # Take input from the user
    n = int(input("Enter the number of people in the circle: "))
    k = int(input("Enter the elimination step (k): "))

    # Create a list representing the circle of people
    circle = list(range(1, n + 1))

    # Initialize the turtle for visualization
    screen = turtle.Screen()
    screen.title("Josephus Problem with Circular Permutation Visualization")
    screen.bgcolor("lightgray")
    t = turtle.Turtle()
    t.speed(2)
    t.width(2)

    # Calculate the angle between each person in the circle
    angle = 360 / n

    for i in range(n):
        t.penup()
        t.goto(200 * math.cos(math.radians(i * angle)), 200 * math.sin(math.radians(i * angle)))
        t.pendown()
        t.write(circle[i], align="center", font=("Arial", 12, "normal"))

    # Add a delay before starting the elimination
    time.sleep(1)

    while len(circle) > 1:
        for _ in range(k - 1):
            # Rotate the circle by angle * (k - 1) degrees
            circle.append(circle.pop(0))

        # Eliminate the k-th person
        eliminated = circle.pop(0)
        print(f"Eliminated: {eliminated}")

        # Visualize the elimination
        t.clear()
        t.penup()
        t.goto(0, -220)
        t.pendown()
        t.write(f"Eliminated: {eliminated}", align="center", font=("Arial", 16, "normal"))

        # Draw the remaining circle with updated numbers and circular permutation gaps
        for i in range(len(circle)):
            t.penup()
            # Calculate the position of each person with circular permutation gaps
            x = 200 * math.cos(math.radians(i * k * angle))
            y = 200 * math.sin(math.radians(i * k * angle))
            t.goto(x, y)
            t.pendown()
            t.write(circle[i], align="center", font=("Arial", 12, "normal"))

        turtle.update()

        # Introduce a delay for better visualization (adjust as needed)
        time.sleep(0.5)

    # Display the survivor
    t.clear()
    t.penup()
    t.goto(0, -220)
    t.pendown()
    t.write(f"Survivor: {circle[0]}", align="center", font=("Arial", 16, "normal"))
    turtle.update()

    turtle.done()

if __name__ == "__main__":
    josephus_circular_permutation()
