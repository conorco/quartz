
# import turtle
# def square(length):
#     "have the turtle draw a square of side <length>"
#     for side in range(4):
#         turtle.forward(length)
#         turtle.left(90)
# turtle.reset()
# square(200)
# turtle.exitonclick()

from turtle import *
color('red', 'yellow')
begin_fill()
while True:
    forward(200)
    left(250)
    if abs(pos()) < 1:
        break
end_fill()
done()
