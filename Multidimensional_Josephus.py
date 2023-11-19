import turtle

def create_grid(rows, cols):
    return [[(i * cols) + j + 1 for j in range(cols)] for i in range(rows)]

def eliminate(grid, rows, cols, step, t):
    total_people = rows * cols
    eliminated = 0
    current_index = 0
    while eliminated < total_people - 1:
        effective_step = step % (total_people - eliminated)
        if effective_step == 0:
            effective_step = total_people - eliminated
        current_index = (current_index + effective_step - 1) % (total_people - eliminated)

        r = current_index // cols
        c = current_index % cols
        eliminated_person = grid[r][c]
        t.clear()
        t.penup()
        t.goto(0, -220)
        t.pendown()
        t.write(f"Eliminated: {eliminated_person}", align="center", font=("Arial", 16, "normal"))

        # Update the grid to simulate elimination
        for i in range(current_index, total_people - eliminated - 1):
            current_row = i // cols
            current_col = i % cols
            next_row = (i + 1) // cols
            next_col = (i + 1) % cols
            grid[current_row][current_col] = grid[next_row][next_col]

        # Replace the eliminated position with a blank space
        last_row = (total_people - eliminated - 1) // cols
        last_col = (total_people - eliminated - 1) % cols
        grid[last_row][last_col] = ' '  # Replace with an empty space

        draw_grid(grid, rows, cols, t)  # Redraw the grid with the updated numbers

        eliminated += 1

    survivor = grid[0][0]
    t.clear()
    t.penup()
    t.goto(0, -220)
    t.pendown()
    t.write(f"Survivor: {survivor}", align="center", font=("Arial", 16, "normal"))

def draw_grid(grid, rows, cols, t):
    t.penup()
    t.goto(-20 * cols, 20 * rows)
    t.pendown()
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] != ' ':  # Draw only if not a blank space
                t.penup()
                t.goto(40 * j, -40 * i)
                t.pendown()
                t.write(grid[i][j], align="center", font=("Arial", 12, "normal"))

def main():
    rows = int(input("Enter the number of rows: "))
    cols = int(input("Enter the number of columns: "))
    step = int(input("Enter the elimination step: "))

    grid = create_grid(rows, cols)

    screen = turtle.Screen()
    screen.title("Multidimensional Josephus Problem Visualization")
    screen.bgcolor("lightgray")
    t = turtle.Turtle()
    t.speed(1)
    t.width(2)

    draw_grid(grid, rows, cols, t)
    eliminate(grid, rows, cols, step, t)

    turtle.done()

if __name__ == "__main__":
    main()
