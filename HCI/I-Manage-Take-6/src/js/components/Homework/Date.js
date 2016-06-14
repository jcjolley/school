import React from "react";

import moment from "moment";

export default class Date extends React.Component {
  render() {
   const hours = moment(this.props.date).format("h:mm a");
   const day = moment(this.props.date).format("MMMM Do");
   const dateStyle = {
      color: "white",
      textAlign: "center",
      float: "right",
      padding: "1px 20px",
      marginRight: "15px",
      position: "relative",
      bottom: "6px",
      borderRadius: "8px"
   }
    return (
      <button class="btn btn-raised btn-info" style={dateStyle}>
        <span>{hours}<br/>{day}</span>
      </button>
    );
  }
}
