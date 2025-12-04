# Problem 2: Homepage

## Project brief
This project required building a **multi-page personal website** using **HTML**, **CSS**, and **JavaScript**. The goal was to introduce myself or any topic of interest while demonstrating an understanding of the core building blocks of the web.

The website had to:

- Contain at least four HTML pages, including `index.html`.
- Allow navigation from any page to any other page through hyperlinks.
- Use at least ten distinct HTML tags (other than `<html>`, `<head>`, `<body>`, `<title>`).
- Include at least one **Bootstrap** component.
- Use a separate `styles.css` file for custom styling.
- Optionally include JavaScript for interactivity.

This problem developed my skills in **frontend structure, styling, layout design, and responsive components**.

## Approach
The exercise focused on designing a clean, functional website and organising multiple pages consistently. Key concepts practiced:

- Structuring pages with semantic HTML (e.g., `<header>`, `<nav>`, `<section>`, `<footer>`)
- Creating internal hyperlinks to ensure full navigation
- Styling with CSS and creating a custom visual identity
- Using **Bootstrap** for layout (grid system), components (cards, navbar), and responsive behaviour
- Optionally adding JavaScript for interactivity (e.g., button actions or DOM manipulation)
- Maintaining a consistent layout across pages by reusing navbars, footers, and styling

---

## My solution

### Description
My homepage consists of four main pages:

- `index.html` — A home page introducing myself and the website.
- `my-background.html` — An explanation of my background and origins.
- `my-education.html` — A page where I talk about my university degree and previous studies.
- `my-passion.html` — An explanation about my writing and some of my published work.

Each page includes:

- A **Bootstrap navbar** allowing navigation across all pages.
- A **Typing Effect** for each page's title.
- Custom CSS for layout, spacing, and visual refinement.
- A consistent style shared through `styles.css`.

### How to use it
1. Navigate to the corresponding folder.
2. Start a server: `http-server`
3. Open the provided link in your browser.
4. Explore the site using the navbar to move between pages.

## Code snippet (index.html excerpt)
Below is an excerpt of `index.html`. The full code and other files are included in this folder.

> Bear in mind that these pages DO NOT use any frameworks (such as Flask or Django) because these were taught in a later module.

```html
<!DOCTYPE html>

<html lang="en">
    <head>
        <!--From the original file provided-->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz" crossorigin="anonymous"></script>
        <link href="styles.css" rel="stylesheet">

        <!--Customising browser tab-->
        <link rel="icon" type="image/x-icon" href="portrait.png">
        <title>Hey, it's Andrew!</title>
    </head>

    <body onload="TypeEffect()">
        <!--Main title with Typing effect-->
        <div class="main-titles">
            <p id="main-title"></p>
        </div>

        <!--Navigation bar-->
        <nav class="navbar navbar-expand-lg custom-navbar">
            <div class="container-fluid justify-content-center">

                <!-- The hamburger button (only appears on mobile) -->
                <button class="navbar-toggler" type="button" data-bs-toggle="collapse"
                    data-bs-target="#navbarNav" aria-controls="navbarNav"
                    aria-expanded="false" aria-label="Toggle navigation">
                    <span class="navbar-toggler-icon"></span>
                </button>

                <!--Menu-->
                <div class="collapse navbar-collapse" id="navbarNav">
                    <ul class="navbar-nav">
                        <li class="nav-item">
                            <a class="nav-link active" aria-current="page" href="index.html">Home</a>
                        </li>
                        <li class="nav-item">
                            <a class="nav-link" href="my-background.html">My background</a>
                        </li>
                        <li class="nav-item">
                            <a class="nav-link" href="my-education.html">My education</a>
                        </li>
                        <li class="nav-item">
                            <a class="nav-link" href="my-passion.html">My passion</a>
                        </li>
                    </ul>
                </div>
            </div>
        </nav>

        <!--Main image-->
        <br>
        <img src="portrait.png" height="500" alt="Portrait photo of Andrew Miranda">
        <!--Introductory paragraph-->
        <br>
        <p class="main-text"><b>Hey, I'm Andrew!</b> I'm a manufacturing engineer transitioning into computer science. <br>I studied Engineering Product Design at university, but now I’m diving into software development. </p>

        <!--Welcome button-->
        <button onclick="WelcomeFunction()">WELCOME, CLICK HERE!</button>
        <hr><p id="welcome-message"></p>

        <!--Accordion-->
        <div class="accordion accordion-flush" id="accordionFlushExample">

            <!--Item 1-->
            <div class="accordion-item">
                <h2 class="accordion-header">
                    <button class="accordion-button collapsed" type="button" data-bs-toggle="collapse" data-bs-target="#flush-collapseOne" aria-expanded="false" aria-controls="flush-collapseOne">
                        What is this website?
                    </button>
                </h2>
                <div id="flush-collapseOne" class="accordion-collapse collapse">
                    <div class="accordion-body">
                        <p>This website is part of one of the problem sets from Harvard’s <i>CS50: Introduction to Computer Science course</i>. It’s a practice project for writing HTML, CSS, and JavaScript, and for implementing features from a library (in this case, Bootstrap).
                        I decided to go for a dark-mode design with black-and-white images.
                        This site gives a short introduction about me — where I’m from, my studies, and my interests.</p>

                        <p>There are four HTML pages: <code>index.html</code>, <code>my-background.html</code>, <code>my-education.html</code>, and <code>my-passion.html</code>.
                        You can navigate between them using the top menu.</p>
                    </div>
                </div>
            </div>
