import { api } from "~/trpc/server";
import { NavBar } from "../_components/navbar";
import { QuestionCard, type QuestionSingle } from "../_components/questionCard";
import { LoadingSpinner } from "../_components/LoadingSpinner";

export default async function Page({
  params,
  searchParams,
}: {
  params: { slug: string };
  searchParams: { [key: string]: string | string[] | undefined };
}) {

  //console.log(searchParams.limit); This prints 2 as passed
  let questions: QuestionSingle[] = [];

  async function fetchQuestions() {
    try {
      const limit = searchParams.limit ?? 2; // Default to 2 if not provided
      const fetchedQuestions = await api.trivia.getQuestions.query({
        limit: Number(limit),
      });
      questions = fetchedQuestions;
    } catch (error) {
      console.error("Failed to fetch questions:", error);
      // Handle the error appropriately
    }
  }

  fetchQuestions().catch((error) => {
    console.error("Error in fetchQuestions:", error);
    // Additional error handling if needed
  });
// Let's create a brand new client component to pass all this data to
  return (
    <main className="...">
      <NavBar />
      <div className="...">
        {questions.length === 0 ? (
          <>
            <LoadingSpinner />
            <p>No questions found</p>
          </>
        ) : (
          questions.map((question) => (
            <QuestionCard key={question.id} question={question} />
          ))
        )}
      </div>
    </main>
  );
}
