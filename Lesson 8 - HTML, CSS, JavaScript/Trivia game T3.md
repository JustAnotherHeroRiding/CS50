## Create a fully fledged trivia game using the t3 stack

#### I do not think that we will need a database but let us see how it will develop
##### Also no auth


### 1. **Quick Play Button**

- A prominent "Quick Play" button that allows users to immediately jump into a game with default settings. This is great for users who want to start playing right away without any customization. #DONE 

### 2. **Custom Game Option**


- Use [React Hook Forms](https://www.react-hook-form.com/) for the forms
- A "Custom Game" or "Create Game" option that expands into a form where users can customize their trivia experience. The form could include fields for:
    - **Number of Questions**: Let users choose how many questions they want in their trivia game.
    - **Categories**: Allow users to select trivia categories (e.g., General Knowledge, History, Science, Entertainment).
    - **Difficulty Level**: Options for Easy, Medium, or Hard questions.
    - **Question Type**: Multiple choice, True/False, or mixed.
    - **Region or Language**: If your trivia API supports different regions or languages, include these options too.

### 3. **Instructions/How to Play**

- A section or link providing a brief overview of how to play the trivia game, rules, scoring system, etc. #DONE 
- This be on the nav and on click it will open a modal with a short explanation
### 4. **Settings**

- A settings option where users can adjust app preferences, sounds, notifications, etc.
### 5. **Feedback or Contact**

- A section for users to provide feedback or get in touch with the developers.

### 6. **High Score and Leaderboards**
- Implement auth with NextAuth so that users can log in
- Link a mysql database could be another planetscale account or perhaps an alternative(do research)