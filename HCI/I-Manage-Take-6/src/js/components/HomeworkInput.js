import React from "react";
import store from "../store/app.js";
import {addHomework} from "../store/actions.js"

export default class HomeworkInput extends React.Component {
  render() {
    const addHW = () => {
       store.dispatch(addHomework(this.input.value, new Date(Date.now())));
    }

    return (
      <li class="list-group-item">
         <div class="input-group">
            <input ref = {node => {this.input = node}}
                   type="text" class="form-control" 
                   id="newHomework" 
                   placeholder="Big essay for English101" />
            <span class="input-group-btn">
               <button class="btn btn-default" type="button" id="datepicker" >Due Date</button>
               <button class="btn btn-default" onClick={addHW} type="button">Submit!</button>
            </span>
         </div>
      </li>
    );
  }
}
