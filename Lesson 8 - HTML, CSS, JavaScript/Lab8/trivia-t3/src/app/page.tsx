import Link from "next/link";
import { NavBar } from "./_components/navbar";
// import { cookies } from "next/headers";
// import { createServerComponentClient } from "@supabase/auth-helpers-nextjs";
// import type { Database } from "./_components/@/lib/supabase";
import { type QuestionSingle } from "./_components/questionCard";

export default async function Home() {
  //Querying the supabase db without prisma
  /* const cookieStore = cookies();
  const supabase = createServerComponentClient<Database>({
    cookies: () => cookieStore,
  });
  const { data } = await supabase.from("notes").select(); */

  const url = "https://the-trivia-api.com/v2/questions?limit=2";
  const getData = async () => {
    try {
      const response = await fetch(`${url}`, {
        method: "GET",
        headers: {
          "Content-Type": "application/json",
        },
      });
      const data = (await response.json()) as QuestionSingle[]; // Use await here
      // eslint-disable-next-line @typescript-eslint/no-unsafe-return
      return data; // Return the typed data
    } catch (err) {
      console.log(err);
      throw new Error("Error fetching trivia questions");
    }
  };

  console.log(getData())

  return (
    <main className="relative flex min-h-screen flex-col items-center bg-gradient-to-t from-blue-100 via-blue-300 to-blue-500 font-sans">
      <NavBar />
      <div className="container flex flex-grow flex-col items-center justify-center gap-12 px-4 py-16 ">
        <Link className="punchy-btn" href={"/game"}>
          Quick Play
        </Link>
      </div>
    </main>
  );
}
