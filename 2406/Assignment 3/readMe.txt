Andy Chia - 101111058

Note, calling delete with localhost:3000/sessions/:sessionId didnt work using the provided html/js from the assignment and works perfectly fine with Postman

Running the server:
    node server.js

Testing the server:
    Creating a session id for no repeated questions:
        post:  localhost:3000/sessions

    list all ids on the system:
        get:  localhost:3000/sessions

    Delete an id on the system
        delete localhost:3000/sessions/:sessionId

    Getting questions:
        localhost:3000/questions

        key:            default:       possible range:

        difficulty      undefined      1 - 3
        category        undefined      1 - 24
        limit           10             infinity but status = 1 when over 500
        id              undefined      server provided

        test questions:
        http://localhost:3000/questions/?difficulty=1
        http://localhost:3000/questions/?difficulty=1&category=1
        http://localhost:3000/questions/?difficulty=1&limit=3&category=1
        http://localhost:3000/questions/?id=XXXXXXXXX
        http://localhost:3000/questions/?difficulty=1&limit=3&id=XXXXXXXXX&category=1