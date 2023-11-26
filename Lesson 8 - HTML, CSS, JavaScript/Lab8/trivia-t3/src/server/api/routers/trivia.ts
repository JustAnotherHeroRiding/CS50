import { z } from "zod";
import { createTRPCRouter, publicProcedure } from "~/server/api/trpc";
import { type QuestionSingle } from "~/app/_components/questionCard";

const url = "https://the-trivia-api.com/v2/questions";

export const triviaRouter = createTRPCRouter({
  /* https://the-trivia-api.com/docs/v2/
  Api docs */

  hello: publicProcedure
    .input(z.object({ text: z.string() }))
    .query(({ input }) => {
      return {
        greeting: `Hello ${input.text}`,
      };
    }),

  getQuestions: publicProcedure
    .input(
      z.object({
        limit: z.number(),
        categories: z.string().optional(),
        difficulty: z.string().optional(),
        region: z.string().optional(),
        tags: z.string().optional(),
        types: z.string().optional(),
        session: z.string().optional(),
        preview: z.string().optional(),
        language: z.string().optional(),
      }),
    )
    .query(async ({ input }) => {
      // Convert all input fields to strings
      const inputAsString = Object.fromEntries(
        Object.entries(input).map(([key, value]) => [key, String(value)]),
      );

      // Constructing the query string from the input object
      const queryParams = new URLSearchParams(inputAsString).toString();
      const requestUrl = `${url}?${queryParams}`;

      try {
        const response = await fetch(requestUrl, {
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
    }), // Closing brace for getQuestions procedure
}); // Closing brace for createTRPCRouter
