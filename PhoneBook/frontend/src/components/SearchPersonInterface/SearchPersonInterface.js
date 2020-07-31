import React from 'react'
import '../sections.css'
import './style.css'

class SearchPersonInterface extends React.Component {


    render() {
        //decide if component is visible or not
        return (
            <div id="searchPersonInterface" className={this.props.isVisible ? "section-visible" : "section-invisible"}>
                <div className="topbar">
                    <h3>Guten Morgen</h3>
                </div>
                <div className="input-textfield">
                    <div className="con-input">
                        <input placeholder="Person" type="text"></input>
                    </div>
                    <button className="submitBtn">Search</button>
                </div>

            </div>
        )
    }
}

export default SearchPersonInterface