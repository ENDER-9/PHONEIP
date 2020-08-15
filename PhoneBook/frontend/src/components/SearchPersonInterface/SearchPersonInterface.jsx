import React from 'react'
import OutputBox from './OutputBox'
import client from '../../../build/Release/client.node'




class SearchPersonInterface extends React.Component {
    constructor() {
        super()
        this.state = {
            firstName: "",
            lastName: "",
            fullName: "",
            isOutputBoxesVisible: false,
            persons: []
        }
        this.handleClick = this.handleClick.bind(this)
        this.handleChange = this.handleChange.bind(this)
        this.splitString = this.splitString.bind(this)
    }
    //Changes fullName, when inputField is changed
    handleChange(event) {
        this.setState({
            fullName: event.target.value
        }, this.splitString);
    }

    //execute the function
    handleClick() {
        let array = [client.sendGetPersonInformationServerJs(this.state.firstName, this.state.lastName)]
        if (array[0].FirstName === 'Not found') {

        }
        else {
            this.setState({
                persons: array,
                isOutputBoxesVisible: true
            })
        }

    }

    //splits the full input into two variables in order to put it in the function
    splitString() {
        var name = this.state.fullName.split(' ')
        this.setState({
            firstName: name[0],
            lastName: name[1]
        })
    }


    render() {

        const personComponents = this.state.persons.map(person => <OutputBox persons={person} />)
        //decide if component is visible or not
        return (
            <div id="searchPersonInterface" className="routed_section">
                <div className="topbar">
                    <h3>Guten Morgen</h3>
                </div>
                <div className="input-textfield">
                    <div className="con-input">
                        <input placeholder="Person" type="text" onChange={this.handleChange} ></input>
                    </div>
                    <button className="submitBtn" onClick={this.handleClick}>Search</button>
                </div>
                <div className={(this.state.isOutputBoxesVisible) ? "output_boxes_active" : "output_boxes"}>
                    {personComponents}
                </div>
            </div >
        )
    }
}

export default SearchPersonInterface