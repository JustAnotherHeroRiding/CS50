"use client";

import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import { faGithub } from "@fortawesome/free-brands-svg-icons";
import Link from "next/link";
import { buttonVariants } from "./@/components/ui/button";

export function NavBar() {
  return (
    <div
      className="sticky left-0 top-0 z-10 flex h-16 w-full items-center justify-between
    border-b-2 border-trivia-400 bg-gradient-to-r from-trivia-400 via-trivia-200 to-trivia-300 px-4 text-trivia-100"
    >
      <div className="flex flex-1 items-center text-start">
        <Link
          href="https://github.com/JustAnotherHeroRiding"
          className={`${buttonVariants({
            variant: "outline",
          })} flex items-center hover:underline`}
          target="_blank"
        >
          JustAnotherHeroRiding
          <FontAwesomeIcon
            icon={faGithub}
            className="ml-2 h-6 w-6 hover:text-trivia-200"
          />
        </Link>
      </div>
      <Link
        href={"/"}
        className={`${buttonVariants({
          variant: "link",
        })}flex-1 text-center `}
      >
        <span className="rounded-lg border bg-trivia-100 p-2 font-sans text-2xl font-black  text-trivia-400">
          Trivial
        </span>
      </Link>
      <div className="flex flex-1 items-center justify-end">
        <Link
          className={`${buttonVariants({
            variant: "outline",
          })}rounded-md gap-2 border p-1`}
          href="/"
        >
          Expanded <span>Version</span>
        </Link>
      </div>
    </div>
  );
}
