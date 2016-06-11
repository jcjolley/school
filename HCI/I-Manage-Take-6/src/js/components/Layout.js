import React from "react";
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
            <ul class="list-group">
              <HomeworkInput />
              {Homeworks}
            </ul>
          </div>
        </div>
        <Footer />
      </div>
    );
  }
}

