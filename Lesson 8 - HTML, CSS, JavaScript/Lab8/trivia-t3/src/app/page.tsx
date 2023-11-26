import { api } from "~/trpc/server";

export default async function Home() {
  const hello = await api.trivia.getQuestions.query({ limit: 2 });

  console.log(hello)

  return (
    <main className="flex min-h-screen flex-col items-center justify-center bg-gradient-to-r from-blue-100 via-blue-300 to-blue-500 font-sans">
      <div className="container flex flex-col items-center justify-center gap-12 px-4 py-16 ">
        <h1>Trivia Game</h1>
      </div>
    </main>
  );
}