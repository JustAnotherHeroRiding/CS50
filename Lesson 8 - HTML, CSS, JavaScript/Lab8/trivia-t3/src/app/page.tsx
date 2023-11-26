import { api } from "~/trpc/server";
import { NavBar } from "./_components/navbar";
import { QuestionCard } from "./_components/questionCard";

export default async function Home() {
  const hello = await api.trivia.getQuestions.query({ limit: 2 });

  return (
    <main className="relative flex min-h-screen flex-col items-center bg-gradient-to-t from-blue-100 via-blue-300 to-blue-500 font-sans">
      <NavBar />
      <div className="container flex flex-grow flex-col items-center justify-center gap-12 px-4 py-16 ">
        <button className="punchy-btn" role="button">
          Quick Play
        </button>
        {hello.map((question) => (
          <QuestionCard key={question.id} question={question} />
        ))}
      </div>
    </main>
  );
}
