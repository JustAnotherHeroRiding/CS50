"use client";

import { Button } from "./@/components/ui/button";

interface AnswerProps {
  text: string;
  isCorrect: boolean;
}

export function Answer({ text, isCorrect }: AnswerProps) {
  return (
    <Button variant={"default"}>
      <h1>{text}</h1>
    </Button>
  );
}
