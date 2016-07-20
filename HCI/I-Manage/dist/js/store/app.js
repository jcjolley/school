import { createStore } from 'redux'
import moment from "moment";

export const ADD_HOMEWORK = 'ADD_HOMEWORK'
export const COMPLETE_HOMEWORK = 'COMPLETE_HOMEWORK'

//actions!
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

let initialState;

//Load items from previous sessions and prime nextHomeworkId
if (localStorage['hw_store'] != null)
{
   initialState = JSON.parse(localStorage['hw_store'])
   nextHomeworkId = initialState.homework_items
      .map(hw => hw.id)
      .reduce((i1, i2) => Math.max(i1, i2)) + 1;

} else {
   initialState = {homework_items: []};
}

//modify our store based on our actions and the current state of the store
function homeworkReducer(state = initialState, action) {
   switch(action.type){
      case ADD_HOMEWORK:
         if (action.text !== "")
            return Object.assign({}, state, {
               homework_items: [
               ...state.homework_items,
               {
                  text:action.text,
                  id: action.id, 
                  date:action.date, 
                  completed:false
               }
               ]
            });
         return state.homework_items;
         break;
      case COMPLETE_HOMEWORK:
         return Object.assign({}, state, {
            homework_items: state.homework_items.map((homework) => {
               if (homework.id === action.id) {
                  return Object.assign({}, homework, {
                     completed: true
                  })
               }
               return homework;
         })
      });
      break;
   default:
      return state;
   } 
}

//actually create our backing store
let store = createStore(homeworkReducer, initialState);

//populate with fake items if there are no visible items;
const visible = store.getState().homework_items
   .filter(hw => !hw.completed);

if (visible.length == 0)
{
   const types = ["Prepare", "Ponder and Prove", "Teach One Another", "Test" ]
   const classes = ["PHYS 101", "MATH 330", "CS 371", "CS 432"];
   for(let i = 0; i < 14; i++){
      for (let j = 0; j < 4; j++) {
         if (Math.random() * 3 < 1) {
            let title = classes[Math.floor(Math.random() * 4)] + " " + types[Math.floor(Math.random() * 4)] + " " + (i + 1);
            store.dispatch(addHomework(title, (moment() + (i * 1000 * 60 * 60 * 24))));
         }
         console.log("Populating with fake items");
      }
   } 
}


//store items as they're added
store.subscribe(() => {
    localStorage.setItem('hw_store', JSON.stringify(store.getState()));
})

export default store;