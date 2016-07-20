import React from "react";
import ReactDOM from "react-dom";
import store from "./store/app.js";

import Layout from "./components/Layout";

const app = document.getElementById('app');

const render = () => {
   ReactDOM.render(<Layout/>, app);
}

store.subscribe(render);
render();
