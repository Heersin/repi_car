import turtle

def draw_love(t):
    for i in range(3):
        t.left(30)
        t.forward(25)

    for i in range(2):
        t.left(45)
        t.forward(37)

    t.left(45)
    t.forward(110)

    t.left(90)
    t.forward(110)

    for i in range(2):
        t.left(45)
        t.forward(37)

    for i in range(3):
        t.left(30)
        t.forward(25)

def draw_magic(t):
    t.forward(25)
    
    t.right(110)
    t.forward(60)

    t.left(110)
    t.forward(75)

    t.left(110)
    t.forward(60)

    t.right(110)
    t.forward(25)

    #edge
    t.right(60)
    for i in range(6):
        t.left(15)
        t.backward(14)

def draw_king(t):
    t.forward(160)
    
    t.left(70)
    t.forward
    (75)

    t.right(30)
    t.backward(50)

    t.left(100)
    t.forward(80)

    t.right(100)
    t.backward(80)

    t.left(100)
    t.forward(50)

    t.right(30)
    t.backward(80)

def draw_gear(t):
    for i in range(4):
        t.forward(30)
        t.left(90)

        t.forward(30)
        t.right(90)

        t.forward(30)
        t.right(90)

        t.forward(30)
        t.left(90)

        t.forward(30)
        t.right(90)

def draw_pope(t):
    t.backward(80)

    t.left(90)
    t.backward(10)

    t.right(90)
    t.forward(80)

    t.left(60)
    t.forward(20)

    t.right(105)
    t.forward(16)

    t.right(45)
    t.forward(25)

    t.right(45)
    t.forward(16)

    t.left(75)
    t.backward(20)


def draw_priest(t):
    t.forward(20)

    t.right(90)
    t.forward(50)

    t.left(90)
    t.forward(50)

    t.right(90)
    t.forward(20)

    t.right(90)
    t.forward(50)

    t.left(90)
    t.forward(50)

    t.right(90)
    t.forward(20)

    t.right(90)
    t.forward(50)

    t.left(90)
    t.forward(125)

    t.right(90)
    t.forward(20)

    t.right(90)
    t.forward(125)

    t.left(90)
    t.forward(50)

def draw_tower(t):
    t.backward(20)

    t.right(10)
    t.backward(80)

    t.right(80)
    t.forward(30)

    t.right(80)
    t.backward(80)

def draw_star(t):
    for i in range(3):
        t.forward(70)
        t.left(36)
        t.backward(70)
        t.left(36)


def draw_moon(t):
    for i in range(7):
        t.forward(30)
        t.right(25)

    t.left(30)

    for i in range(8):
        t.backward(24)
        t.left(20)

def draw_sun(t):
    distance = 10
    for i in range(8):
        t.down()
        t.forward(distance)
        distance = distance + 10
        t.up()
        t.right(90)

    # adjusting location
    t.right(90)
    t.forward(90)


    # 5 point represent the sunshine
    t.left(45)
    t.forward(30)
    t.down()
    t.forward(20)
    t.up()


    t.left(45)
    t.backward(40)
    t.left(90)
    t.down()
    t.forward(20)
    t.up()


    t.left(90)
    t.forward(40)
    t.left(45)
    t.down()
    t.backward(20)
    t.up()

    t.left(45)
    t.backward(40)
    t.left(90)
    t.down()
    t.backward(20)
    t.up()

    t.left(90)
    t.forward(40)
    t.left(45)
    t.down()
    t.backward(20)
    t.up()



if __name__ == "__main__":
    t = turtle.Turtle()
    draw_love(t)
    a = input()