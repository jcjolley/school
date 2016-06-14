import React from "react";

import Checkbox from "./Checkbox.js";
import HWDate from "./Date"; 
import Title from "./Title";

export default class Homework extends React.Component {
  render() {

    const rowStyle = {
    }

    return (
      <li class="list-group-item">
        <div class="row" style={rowStyle}>
          <Title title={this.props.title} />
          <div class="col-sm-5">
            <Checkbox hwid={this.props.hwid} />
            <HWDate date={this.props.date} />
          </div>
        </div>
      </li>
    );
  }
}
