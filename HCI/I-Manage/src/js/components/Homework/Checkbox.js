import React from "react";
import store from "../../store/app";
import {completeHomework} from "../../store/actions"

export default class Checkbox extends React.Component {
   render() {

   const imgStyle = {
      width: "40px",
      borderRadius: "8px",
      padding: "0px",
      margin: "0px",
      position: "relative",
      right: "10px",
      bottom: "2px"
   };

   const buttonStyle = {
      width: "50px",
      height: "50px",
      borderRadius: "8px",
      position: "relative",
      bottom: "7px",
      float: "right"
   }

   const complete = () => {
      store.dispatch(completeHomework(this.props.hwid));
   }

    return (
        <button class="btn btn-raised btn-success" 
                onClick={complete}
                style={buttonStyle}>
          <img src="img/checkbox.png" 
               style={imgStyle} />
        </button>
    );
  }
}
