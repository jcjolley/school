import React, {PropTypes} from 'react'

const Homework = ({ onClick, completed, text}) => {
   <li
      onClick = {onClick}
      style={{
         textDecoration: completed? 'line-through' : 'none'
      }}
   >
      {text}
   </li>
}

Homework.propTypes = {
   onClick: PropTypes.func.isRequired,
   completed: PropTypes.bool.isRequired,
   text: PropTypes.string.isRequired
}

export default Homework