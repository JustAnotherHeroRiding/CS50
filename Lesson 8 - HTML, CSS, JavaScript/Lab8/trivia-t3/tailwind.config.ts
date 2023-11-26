import { type Config } from "tailwindcss";

export default {
  content: ["./src/**/*.tsx"],
  theme: {
    extend: {
      fontFamily: {
        sans: [
          '"Soehne"',
          "system-ui",
          "-apple-system",
          "Helvetica Neue",
          "Arial",
          "sans-serif",
        ],
        // circle: ['"Soehne Circle"', 'sans-serif'],
        serif: [
          '"Signifier"',
          "ui-serif",
          "Georgia",
          "Cambria",
          "Times New Roman",
          "Times",
          "serif",
        ],
        mono: ['"Soehne Mono Buch"', "Courier", "monospace"],
      },
      colors: {
        radio: {
          100: "#003049",
          200: "#d62828",
          300: "#f77f00",
          400: "#fcbf49",
          500: "#eae2b7",
          600: "#1d1f20",
        },
        trivia: {
          100: "#F6F1F1",
          200: "#19A7CE",
          300: "#146C94",
          400: "#000000",
        },
      },
    },
  },
  plugins: [],
} satisfies Config;
