export type Json =
  | string
  | number
  | boolean
  | null
  | { [key: string]: Json | undefined }
  | Json[]

export interface Database {
  public: {
    Tables: {
      Question: {
        Row: {
          category: string
          correctAnswer: string
          difficulty: string
          id: string
          incorrectAnswers: string[] | null
          isNiche: boolean
          questionText: string
          regions: string[] | null
          tags: string[] | null
          type: string
        }
        Insert: {
          category: string
          correctAnswer: string
          difficulty: string
          id: string
          incorrectAnswers?: string[] | null
          isNiche: boolean
          questionText: string
          regions?: string[] | null
          tags?: string[] | null
          type: string
        }
        Update: {
          category?: string
          correctAnswer?: string
          difficulty?: string
          id?: string
          incorrectAnswers?: string[] | null
          isNiche?: boolean
          questionText?: string
          regions?: string[] | null
          tags?: string[] | null
          type?: string
        }
        Relationships: []
      }
    }
    Views: {
      [_ in never]: never
    }
    Functions: {
      [_ in never]: never
    }
    Enums: {
      [_ in never]: never
    }
    CompositeTypes: {
      [_ in never]: never
    }
  }
}
