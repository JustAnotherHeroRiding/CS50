"use client";

interface AnswerProps {
  text: string;
  isCorrect: boolean;
}

export function Answer({ text, isCorrect }: AnswerProps) {
  return (
    <div>
      <h1>{text}</h1>
    </div>
  );
}
