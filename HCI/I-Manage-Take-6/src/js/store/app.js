import { createStore } from 'redux'
import { ADD_HOMEWORK, COMPLETE_HOMEWORK, addHomework, completeHomework} from './actions'

const initialState = { homework_items: [] }

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

let store = createStore(homeworkReducer);

store.dispatch(addHomework("Get the prototype finished", new Date(Date.now())))
store.dispatch(addHomework("Get the spec finished", new Date(Date.now())))
store.dispatch(addHomework("Don't fail this class!", new Date(Date.now())))

export default store;