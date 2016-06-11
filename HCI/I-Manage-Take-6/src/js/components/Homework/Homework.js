import React from "react";

import Checkbox from "./Checkbox.js";
import HWDate from "./Date"; 
import Title from "./Title";

export default class Homework extends React.Component {
  render() {

    return (
      <li class="list-group-item">
        <div class="row">
          <Title title={this.props.title} />
          <HWDate date={this.props.date} />
          <Checkbox hwid={this.props.hwid} />
        </div>
      </li>
    );
  }
}
