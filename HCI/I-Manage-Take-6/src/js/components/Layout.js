import React from "react";
import ReactCSSTransitionGroup from 'react-addons-css-transition-group';
import store from "../store/app.js";
import Footer from "./Footer";
import Header from "./Header";
import Homework from "./Homework/Homework";
import HomeworkInput from "./HomeworkInput";

export default class Layout extends React.Component {
  render() {

    let Homeworks = store.getState().homework_items
          .filter( hw => hw.completed === false)
          .map( hw =>
        <Homework key={hw.id} hwid={hw.id} date={hw.date} title={hw.text} />
      );

    return (
      <div class="container">
        <Header />
        <div class="row">
          <div class="col-sm-12">
            <ul class="card list-group">
              <HomeworkInput />
              <ReactCSSTransitionGroup transitionName="example" transitionEnterTimeout={500} transitionLeaveTimeout={300}>
                {Homeworks}
              </ReactCSSTransitionGroup>
            </ul>
          </div>
        <Footer />
        </div>
      </div>
    );
  }
}

