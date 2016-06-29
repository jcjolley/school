import React from "react";
import store from "../store/app.js";
import {addHomework} from "../store/app.js"
import moment from "moment";

export default class HomeworkInput extends React.Component {
  render() {

 

    const addHW = () => {
      console.log(this.input.value);
      if (this.input.value == "")
      {
        $('#homeworkInputLI').append('<div class="alert alert-warning"> <a href="#" class="close" data-dismiss="alert" aria-label="close">&times;</a> Your homework needs a title before you can add it. </div>');
        return;
      }
      date = moment(this.dateInput.value, "h:mm a, MMMM Do")

      if (!date.isValid())
        date = moment();

      store.dispatch(addHomework(this.input.value, date));
      this.input.value = "";
      this.input.placeholder = "You can do it!";
      this.dateInput.value = "";
      this.dateInput.placeholder = "No day like today."
    }

    const inputStyle = {
      width: "78%",
      fontSize: "120%",
      padding: "17px 0px 0px 0px"
    }

    const submitStyle = {
      width: "40px",
      borderRadius: "8px",
      padding: "0px",
      margin: "0px",
      position: "relative",
      right: "10px",
    };

    const calStyle = {
      width: "45px",
      borderRadius: "8px",
      padding: "0px",
      margin: "0px",
      position: "relative",
      right: "13px",
      bottom: "4px"
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
      marginRight: "20px",
      position: "relative",
      right: "2px"
    }

    const dpStyle = {
      width: "20%",
      padding: "17px 0px 0px 0px"
    }

    const toggleDatePicker = () => {
      $("#datepicker").datetimepicker('show');
    }

    const handleTextEnter = (e) => {
      if (e.keyCode == 13)
        $("#datepicker").datetimepicker('show');
    }

    return (
      <li class="list-group-item" id="homeworkInputLI">
        <div class="input-group">
          <input ref = {node => {this.input = node}}
                 type="text" class="form-control" 
                 id="newHomework" 
                 placeholder="Enter your homework here"
                 style={inputStyle}
                 onKeyUp={handleTextEnter}
                 tabindex="1" />
          <input ref = {node => {this.dateInput = node}}
                 type="text" 
                 class="form-control"
                 id="datepicker" 
                 style={dpStyle}
                 tabindex="2" />
          <div class="input-group-btn" >
            <button class="btn btn-raised btn-info" 
                    type="button" 
                    id="datepicker" 
                    style={calButtonStyle}
                    onClick={toggleDatePicker}>
              <img src="img/calendar.png" 
                   style={calStyle} />                    
            </button>
            <button class="btn btn-raised btn-success" 
                    onClick={addHW} 
                    type="button"
                    style={buttonStyle}
                    tabindex="3">
              <img src="img/submit.png" style={submitStyle} />
            </button>
          </div>
        </div>
      </li>
    );
  }
}
