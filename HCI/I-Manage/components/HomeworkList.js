import React, { PropTypes } from 'react'
import Homework from './Homework'

const Homework = ({ homework_items, onHomeworkClick}) => (
   <ul>
      {homework_items.map(homework =>
         <Homework
            key={homework.id}
         )}
   </ul>   
)
