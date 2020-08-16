import React from 'react';
import { Button, Link } from 'react-router-dom'

class Nav extends React.Component {
    render() {
        return (
            <div className="sidebar">
                <div className="bar-title">
                    <h1>Phone Book</h1>
                </div>
                <ul>
                    <Link to='/searchPersonInterface' style={{ outline: 0 }}>
                        <button id="searchBtn" className="nav-button">
                            <h5>Search Person</h5>
                        </button>
                    </Link>

                    <Link to='/addPersonInterface' style={{ outline: 0 }}>
                        <button id="addBtn" className="nav-button">
                            <h5>Add Person</h5>
                        </button>
                    </Link>
                </ul>
            </div>
        )
    }

}

export default Nav

