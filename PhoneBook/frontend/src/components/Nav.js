import React from 'react'
import './Nav.css'
import './sections.css'

class Nav extends React.Component {
    render() {
        return (
            <div className="wrapper" >
                <div className="sidebar">
                    <div className="bar-title">
                        <h1>Phone Book</h1>
                    </div>
                    <ul>
                        <button className="nav-button" onClick={this.props.updateSearchPerson}>
                            <h5>Search Person</h5>
                        </button>
                        <button className="nav-button" onClick={this.props.updateAddPerson}>
                            <h5>Add Person</h5>
                        </button>
                        <button className="nav-button" onClick={this.props.updateDeletePerson}>
                            <h5>Delete Person</h5>
                        </button>
                        <button className="nav-button" onClick={this.props.updateModifyPerson}>
                            <h5>Modify Person</h5>
                        </button>
                    </ul>
                </div>
            </div>
        )
    }

}

export default Nav