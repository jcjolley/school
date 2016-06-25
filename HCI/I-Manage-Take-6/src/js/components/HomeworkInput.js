import React from "react";
import store from "../store/app.js";
import {addHomework} from "../store/actions.js"

export default class HomeworkInput extends React.Component {
  render() {
    const addHW = () => {
       store.dispatch(addHomework(this.input.value, new Date(Date.now())));
    }

    const inputStyle = {
      width: "78%",
      fontSize: "120%"
    }

    const submitStyle = {
      width: "40px",
      borderRadius: "8px",
      padding: "0px",
      margin: "0px",
      position: "relative",
      right: "12px",
      bottom: "2px"
   };

    const calStyle = {
      width: "40px",
      borderRadius: "8px",
      padding: "0px",
      margin: "0px",
      position: "relative",
      right: "11px",
      bottom: "2px"
    };

   const buttonStyle = {
      width: "50px",
      height: "50px",
      borderRadius: "8px"
   }

   const calButtonStyle = {
      width: "50px",
      height: "50px",
      borderRadius: "8px",
      marginRight: "20px"
   }

   const dpStyle = {
      width: "20%"
   }

   const toggleDatePicker = () => {
     var si = document.getElementById('show_inline').style; 
     si.display = (si.display=='none') ? 'block' : 'none';
     return false; 
   }

    return (
      <li class="list-group-item">
         <div class="input-group">
            <input ref = {node => {this.input = node}}
                   type="text" class="form-control" 
                   id="newHomework" 
                   placeholder="Enter your homework here"
                   style={inputStyle} />
            <input type="text" class="form-control"
                   id="datepicker" style={dpStyle} />
               <span class="input-group-btn" >
               <button class="btn btn-raised btn-info" type="button" id="datepicker" 
                       style={calButtonStyle}
                       onClick={toggleDatePicker}>
                <img src="img/calendar.png" style={calStyle} />                    
               </button>
               <button class="btn btn-raised btn-success" onClick={addHW} type="button"
                       style={buttonStyle}>
                <img src="img/submit.png" style={submitStyle} />
               </button>
            </span>
         </div>
      </li>
    );
  }
}
