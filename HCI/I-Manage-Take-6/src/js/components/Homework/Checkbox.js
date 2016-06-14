import React from "react";
import store from "../../store/app";
import {completeHomework} from "../../store/actions"

export default class Checkbox extends React.Component {
   render() {

   const checkboxStyle = {
      width: "40px",
   };

   const complete = () => {
      store.dispatch(completeHomework(this.props.hwid)) 
   }

    return (
      <div class="col-sm-1">
         <img src="img/checkbox.png" 
              style={checkboxStyle}
              onClick={complete} />
      </div>
    );
  }
}
