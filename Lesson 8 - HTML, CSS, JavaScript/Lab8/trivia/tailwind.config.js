/** @type {import('tailwindcss').Config} */
module.exports = {
  content: ["./src/**/*.{html,js}"],
  safelist: [
    "bg-trivia-200",
    "text-trivia-400",
    "bg-red-600",
    "bg-green-600",
    "w-1/2",
    "w-1/3",
    "border",
    "border-black",
    "rounded-md",
    "px-4",
    "py-2",
    "text-red-600",
    "text-green-600",
    "text-2xl",
    "my-4"
  ],
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
};
