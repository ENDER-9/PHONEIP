import React from 'react'
import './Nav.css'
import './sections.css'

class Nav extends React.Component {
    render() {
        return (
            <div className="sidebar">
                <div className="bar-title">
                    <h1>Phone Book</h1>
                </div>
                <ul>
                    <button id="searchBtn" className="nav-button" onClick={this.props.updateSearchPerson}>
                        <h5>Search Person</h5>
                    </button>
                    <button id="addBtn" className="nav-button" onClick={this.props.updateAddPerson}>
                        <h5>Add Person</h5>
                    </button>
                </ul>
            </div>
        )
    }

}

export default Nav