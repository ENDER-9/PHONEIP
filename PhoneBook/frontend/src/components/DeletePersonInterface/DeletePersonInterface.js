import React from 'react'
import '../sections.css'

class DeletePersonInterface extends React.Component {

    render() {
        //decide if component is visible or not
        return (
            <div id="deletePersonInterface" className={this.props.isVisible ? "section-visible" : "section-invisible"
            }>
                <h1>Delete</h1>
            </div>
        )
    }
}

export default DeletePersonInterface