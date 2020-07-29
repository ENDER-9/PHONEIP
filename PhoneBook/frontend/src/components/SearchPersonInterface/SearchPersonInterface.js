import React from 'react'
import '../sections.css'

class SearchPersonInterface extends React.Component {


    render() {
        //decide if component is visible or not
        return (
            <div id="searchPersonInterface" className={this.props.isVisible ? "section-visible" : "section-invisible"}>
                <h1>Search</h1>
            </div>
        )
    }
}

export default SearchPersonInterface