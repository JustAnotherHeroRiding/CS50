"use client";

import { useRouter } from "next/navigation";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import { faGithub } from "@fortawesome/free-brands-svg-icons";
import Link from "next/link";

export function NavBar() {
  const router = useRouter();

  return (
    <div className="sticky left-0 top-0 flex h-16 w-full items-center justify-between z-10
    border-b-2 border-trivia-400 bg-gradient-to-r from-trivia-400 via-trivia-200 to-trivia-300 px-4 text-trivia-100">
      <div className="flex flex-1 items-center text-start">
        <Link
          href="https://github.com/JustAnotherHeroRiding"
          className="hover:underline flex items-center"
          target="_blank"
        >
          JustAnotherHeroRiding
          <FontAwesomeIcon
            icon={faGithub}
            className="ml-2 h-6 w-6 hover:text-trivia-200"
          />
        </Link>
      </div>
      <h1
        onClick={() => router.push("/")}
        className="flex-1 text-center text-trivia-400"
      >
        <span className="rounded-lg border bg-trivia-100 p-2 font-serif text-2xl font-bold">
          Trivial
        </span>
      </h1>
      <div className="flex flex-1 items-center justify-end">
        <a className="rounded-md border p-1" href="expanded.html">
          Expanded <span>Version</span>
        </a>
      </div>
    </div>
  );
}
