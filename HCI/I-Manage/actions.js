//action types
export const ADD_HOMEWORK = 'ADD_HOMEWORK'
export const COMPLETE_HOMEWORK = 'COMPLETE_HOMEWORK'

//action creators
let nextHomeworkId = 0;
export function addHomework(text, date)
{
   return {type: ADD_HOMEWORK, 
           id: nextHomeworkId++,
           text, date};
}

export function completeHomework(id)
{
   return {type: COMPLETE_HOMEWORK, id}
}
