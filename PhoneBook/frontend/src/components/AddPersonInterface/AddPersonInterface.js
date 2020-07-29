import React from 'react'
import '../sections.css'
import './style.css'

class AddPersonInterface extends React.Component {

    render() {
        //decide if component is visible or not
        return (
            <div id="addPersonInterface" className={this.props.isVisible ? "section-visible" : "section-invisible"}>
                <div className="topbar">
                    <h3>Normal</h3>
                    <h3>Map</h3>
                </div>
                <h1>AddPerson</h1>
            </div>
        )
    }
}

export default AddPersonInterface