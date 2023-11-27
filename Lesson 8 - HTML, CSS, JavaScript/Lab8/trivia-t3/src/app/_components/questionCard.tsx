import { Card } from "./@/components/ui/card";
import { Answer } from "./Answer";

export interface QuestionSingle {
  category: string;
  id: string;
  correctAnswer: string;
  incorrectAnswers: string[];
  question: { text: string };
  tags: [string];
  type: string;
  difficulty: string;
  regions: string[];
  isNiche: boolean;
}
interface QuestionCardProps {
  question: QuestionSingle;
}

export function QuestionCard({ question }: QuestionCardProps) {
    const allAnswers = [
      ...question.incorrectAnswers.map(answer => ({ text: answer, isCorrect: false })),
      { text: question.correctAnswer, isCorrect: true }
    ];
  
    allAnswers.sort(() => Math.random() - 0.5);
  
    return (
      <Card className="p-4">
        {allAnswers.map((answer, index) => (
          <Answer key={index} text={answer.text} isCorrect={answer.isCorrect} />
        ))}
      </Card>
    );
  }
