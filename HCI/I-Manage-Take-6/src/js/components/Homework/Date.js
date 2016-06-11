import React from "react";

import moment from "moment";

export default class Date extends React.Component {
  render() {
   const hours = moment(this.props.date).format("h:mm a");
   const day = moment(this.props.date).format("MMMM Do");
   const dateStyle = {
      color: "white"
   }
    return (
      <div class="col-sm-2 text-primary text-center bg-primary" style={dateStyle}>{hours}<br/>{day}</div>
    );
  }
}
