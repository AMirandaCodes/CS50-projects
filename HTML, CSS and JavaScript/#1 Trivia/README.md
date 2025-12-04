# Problem 1: Trivia

## Project brief
This project consists of creating an **interactive trivia webpage** that allows users to answer two types of questions:

- A **multiple-choice question** (Part 1)  
- A **free-response question** (Part 2)

The webpage must be implemented using **HTML**, **CSS**, and **JavaScript**, and should provide visual feedback to the user based on whether their answer is correct or incorrect.

The project requirements include:

- Structuring the page with HTML headings, buttons, and input fields.
- Styling the page with CSS.
- Using JavaScript to:
  - Change button/input colours depending on the correctness of the answer.
  - Display text such as *“Correct!”* or *“Incorrect”* under each question.
  - Detect button clicks and form submissions.
- Ensuring exactly **one correct answer** in the multiple-choice section.

## Approach
This problem developed my skills with **client-side interactivity**, bringing together:

- DOM selection and event listeners
- Dynamic styling with JavaScript
- Real-time user feedback
- Clean HTML structure and semantic tags
- Basic CSS styling for usability

The program listens for user interactions (clicks or submissions) and updates the page dynamically by modifying elements’ colors and text content.

---

## My solution

### Description
The webpage:

- Presents a multiple-choice trivia question with three answer options:
  - Correct answer → turns **green** and displays *“Correct!”*
  - Incorrect answers → turn **red** and display *“Incorrect”*
- Includes a free-response question:
  - When the user submits an answer, the input field turns green/red
  - Displays feedback based on whether the answer matches the correct one
- Uses `DOMContentLoaded` to ensure all elements are loaded before attaching event listeners.

### How to use it
1. Open the folder containing `index.html` and `styles.css`.
2. Launch the webpage by opening `index.html` in a browser.
3. Click the multiple-choice options or type your answer in the free-response field.
4. Observe real-time feedback in colour and on-screen text.

### Code snippet (index.html)
```html
<!DOCTYPE html>

<html lang="en">
    <head>
        <link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@500&display=swap" rel="stylesheet">
        <link href="styles.css" rel="stylesheet">
        <title>Trivia!</title>
        <script>
            // Run script once DOM is loaded
            document.addEventListener('DOMContentLoaded', function(){

                // When the correct answer is clicked, change color to green
                let correct = document.querySelector('.correct');
                correct.addEventListener('click', function() {
                    correct.style.backgroundColor = 'green';

                    // Displays 'Correct!' in green
                    let message = document.querySelector('#feedback1');
                    message.innerHTML = 'Correct!';
                    message.style.color = 'green';
                });

                // When an incorrect answer is clicked, change to red
                let incorrects = document.querySelectorAll(".incorrect");
                for (let i = 0; i < incorrects.length; i++)
                {
                    incorrects[i].addEventListener('click', function(){
                        incorrects[i].style.backgroundColor = 'red';

                        let message = document.querySelector('#feedback1');
                        message.innerHTML = 'Incorrect';
                        message.style.color = 'red';
                    });
                }

                // Free-response question logic
                document.querySelector('#check-answer').addEventListener('click', function() {
                    let input = document.querySelector('#response');
                    let feedback = document.querySelector('#feedback2');

                    if (input.value.trim().toLowerCase() === 'tokyo') {
                        input.style.backgroundColor = 'green';
                        feedback.innerHTML = 'Correct!';
                        feedback.style.color = 'green';
                    }
                    else {
                        input.style.backgroundColor = 'red';
                        feedback.innerHTML = 'Incorrect';
                        feedback.style.color = 'red';
                    }
                });
            });
        </script>
    </head>
    <body>
        <h1>Trivia</h1>

        <h2>Part 1: Multiple Choice</h2>
        <h3>What is the largest planet in our solar system?</h3>

        <button class="incorrect">Earth</button>
        <button class="incorrect">Mars</button>
        <button class="correct">Jupiter</button>

        <p id="feedback1"></p>

        <h2>Part 2: Free Response</h2>
        <h3>What is the capital of Japan?</h3>

        <input type="text" id="response">
        <button id="check-answer">Check Answer</button>

        <p id="feedback2"></p>
    </body>
</html>
