import React from 'react'
import '../sections.css'
import './style.css'

class AddPersonInterface extends React.Component {

    render() {
        //decide if component is visible or not
        return (
            <div id="addPersonInterface" className={this.props.isVisible ? "section-visible" : "section-invisible"}>
                <div className="topbar">
                    <div className="decideField">
                        <h3>Normal</h3>
                        <h3>Map</h3>
                    </div>
                </div>
                <div className="addPerson-textfield">
                    <div className="inner-wrapper">
                        <div className="section-wrapper">
                            <h3>Person</h3>
                            <div className="person-inputFields">
                                <div className="first-lastName-input">
                                    <div className="firstName-inputField">
                                        <div className="input-heading">
                                            <p>First name</p>
                                        </div>
                                        <div className="input-field">
                                            <input placeholder="John" type="text" />
                                        </div>
                                    </div>
                                    <div className="lastName-inputField">
                                        <div className="input-heading">
                                            <p>Last name</p>
                                        </div>
                                        <div className="input-field">
                                            <input placeholder="Doe" type="text" />
                                        </div>
                                    </div>
                                </div>
                                <div className="birthday-input">
                                    <div className="input-heading">
                                        <p>Birthday</p>
                                    </div>
                                    <div className="input-field">
                                        <input placeholder="31.12.1900" type="text" />
                                    </div>
                                </div>
                            </div>
                        </div>
                        <div className="section-wrapper">
                            <h3>Contakt Information</h3>
                            <div className="contaktInformation-inputFields">
                                <div className="landlineNumber-input">
                                    <div className="input-heading">
                                        <p>Landline number</p>
                                    </div>
                                    <div className="input-field">
                                        <input placeholder="00000/1111111" type="text" />
                                    </div>
                                </div>
                                <div className="mobilePhoneNumber-input">
                                    <div className="input-heading">
                                        <p>Mobile phone number</p>
                                    </div>
                                    <div className="input-field">
                                        <input placeholder="0152/000000000" type="text" />
                                    </div>
                                </div>
                            </div>
                        </div>
                        <div className="section-wrapper">
                            <h3>Address</h3>
                            <div className="address-inputFields">
                                <div className="street-input">
                                    <div className="input-heading">
                                        <p>Street</p>
                                    </div>
                                    <div className="input-field">
                                        <input placeholder="Examplestreet 24" type="text" />
                                    </div>
                                </div>
                                <div className="postcode-city-input">
                                    <div className="postcode-inputField">
                                        <div className="input-heading">
                                            <p>Postcode</p>
                                        </div>
                                        <div className="input-field">
                                            <input placeholder="00000" type="text" />
                                        </div>
                                    </div>
                                    <div className="city-inputField">
                                        <div className="input-heading">
                                            <p>City</p>
                                        </div>
                                        <div className="input-field">
                                            <input placeholder="Examplecity" type="text" />
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <button className="addBtn">SUBMIT</button>
                </div>
            </div>
        )
    }
}

export default AddPersonInterface