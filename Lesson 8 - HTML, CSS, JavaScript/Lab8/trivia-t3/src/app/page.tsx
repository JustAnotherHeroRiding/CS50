import Link from "next/link";
import { NavBar } from "./_components/navbar";

export default async function Home() {

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
