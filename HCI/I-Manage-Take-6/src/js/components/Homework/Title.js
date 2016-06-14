import React from "react";

export default class Title extends React.Component {
  render() {
    return (
      <div class="col-sm-7 lead">{this.props.title}</div> 
    );
  }
}
