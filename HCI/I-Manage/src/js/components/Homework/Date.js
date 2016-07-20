import React from "react";

import moment from "moment";

export default class Date extends React.Component {
  render() {
   const mdate = moment(this.props.date);
   const hours = mdate.format("h:mm a");
   const day = mdate.format("MMMM Do");

   const getStyle = (diff) => {
    let style = {
      color: "white",
      textAlign: "center",
      float: "right",
      padding: "1px 20px",
      marginRight: "15px",
      position: "relative",
      borderRadius: "8px",
    }
    switch (diff)
    {
      case 0:
        style["backgroundColor"] = "hsl(224.1, 80%, 57.6%)";
        style["borderColor"] = "hsl(224.1, 80%, 57.6%)";
        break;
      case 1:
      case 2: 
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
        style["backgroundColor"] = "hsl(224.1, 40%, 60%)";
        style["borderColor"] = "hsl(224.1, 40%, 60%)";
        break;
      default:
        style["backgroundColor"] = "hsl(224.1, 10%, 70%)";
        style["borderColor"] = "hsl(224.1, 10%, 70%)";
    }
    return style;
   }


   const diff = Math.floor(Math.abs((moment() - mdate) / 1000 /60 /60 /24));
   let dateStyle = {
      color: "white",
      textAlign: "center",
      float: "right",
      padding: "1px 20px",
      marginRight: "15px",
      position: "relative",
      borderRadius: "8px",
      backgroundColor: "hsl(224.1,45.4%,57.6%)",
      borderColor: "hsl(224.1,45.4%,57.6%)" 
   }
   let soonStyle = {
      color: "white",
      textAlign: "center",
      float: "right",
      padding: "1px 20px",
      marginRight: "15px",
      position: "relative",
      borderRadius: "8px",
      backgroundColor: "hsl(224.1,100%, 20.6%)",
      borderColor: "hsl(224.1,100%, 20.6%)" 
   }
    return (
      <button class="alert alert-info" style={getStyle(diff)}>
        <span>{hours}<br/>{day}</span>
      </button>
    );
  }
}
