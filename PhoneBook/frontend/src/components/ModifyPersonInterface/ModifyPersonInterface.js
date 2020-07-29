import React from 'react'
import '../sections.css'

class ModifyPersonInterface extends React.Component {

    render() {
        //decide if component is visible or not
        return (
            <div id="modifyPersonInterface" className={this.props.isVisible ? "section-visible" : "section-invisible"
            }>
                <h1>Modify</h1>
            </div>
        )
    }
}

export default ModifyPersonInterface