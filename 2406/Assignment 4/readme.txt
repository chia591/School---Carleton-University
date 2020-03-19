Andy Chia - 101111048

COMP 2406 - Assignment 4

Since i wasnt able to figure out pug and cant find enough examples to create a pug html page, i wasnt able to complete GET/createquiz.
this makes the POST/quizzes, GET/quizzes and GET/quiz/:quizID not possible to be tested but the code is completed.

Initialize the mongodb
    node database-initializer.js

Run the server
    node server.js

In browser:
    http://localhost:3000/questions

    You can click to any of the questions or:
    http://localhost:3000/questions?difficulty=easy

    or:
    http://localhost:3000/questions?category=Entertainment:%20Books

    or:
    http://localhost:3000/questions?category=Entertainment:%20Books&difficulty=hard

    you can click any of the results to bring up the specific question.