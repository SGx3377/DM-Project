import turtle
import time
import math

def multidimensional_josephus(rows, cols, step):
    # Create a 2D grid representing the circle of people
    circle = [[(i * cols) + j + 1 for j in range(cols)] for i in range(rows)]

    # Initialize the turtle for visualization
    screen = turtle.Screen()
    screen.title("Multidimensional Josephus Problem Visualization")
    screen.bgcolor("lightgray")
    t = turtle.Turtle()
    t.speed(2)
    t.width(2)

    # Draw the initial grid
    for i in range(rows):
        for j in range(cols):
            t.penup()
            t.goto(40 * j, -40 * i)
            t.pendown()
            t.write(circle[i][j], align="center", font=("Arial", 12, "normal"))

    # Add a delay before starting the elimination
    time.sleep(1)

    while len(circle) > 1:
        for _ in range(step - 1):
            # Rotate the rows by step - 1
            circle.append(circle.pop(0))

        # Eliminate the person at the current position
        eliminated = circle[0].pop(0)
        print(f"Eliminated: {eliminated}")

        # Visualize the elimination
        t.clear()
        t.penup()
        t.goto(0, -220)
        t.pendown()
        t.write(f"Eliminated: {eliminated}", align="center", font=("Arial", 16, "normal"))

        # Draw the remaining grid with updated numbers
        for i in range(len(circle)):
            for j in range(len(circle[i])):
                t.penup()
                t.goto(40 * j, -40 * i)
                t.pendown()
                t.write(circle[i][j], align="center", font=("Arial", 12, "normal"))

        turtle.update()

        # Introduce a delay for better visualization (adjust as needed)
        time.sleep(0.5)

        # Remove empty rows
        circle = [row for row in circle if row]

    # Display the survivor
    t.clear()
    t.penup()
    t.goto(0, -220)
    t.pendown()
    t.write(f"Survivor: {circle[0][0]}", align="center", font=("Arial", 16, "normal"))
    turtle.update()

    turtle.done()

if __name__ == "__main__":
    rows = int(input("Enter the number of rows: "))
    cols = int(input("Enter the number of columns: "))
    step = int(input("Enter the elimination step: "))
    multidimensional_josephus(rows, cols, step)
