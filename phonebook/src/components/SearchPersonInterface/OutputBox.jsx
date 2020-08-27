import React from 'react'

function OutputBox(props) {

    //decide if component is visible or not
    return (
        <div className="output_box">
            <div className="output_box_padding">
                <div className="name_field">
                    <h3>{props.persons.firstName} {props.persons.lastName}</h3>
                </div>
                <div id="phone_birthday_field" className="field">
                    <div className="text_field">
                        <h5>Phone Number:</h5>
                        <h5>{props.persons.phoneNumber}</h5>
                    </div>
                    <div className="text_field">
                        <h5>Birthday:</h5>
                        <h5>{props.persons.birthday}</h5>
                    </div>
                </div>
                <div id="landline_address_field" className="field">
                    <div className="text_field">
                        <h5>Landline Number:</h5>
                        <h5>{props.persons.landlineNumber}</h5>
                    </div>
                    <div className="text_field">
                        <h5>Address:</h5>
                        <div className="address_fields">
                            <h5>{props.persons.city}</h5>
                            <h5>{props.persons.street}</h5>
                            <h5>{props.persons.postcode} {props.persons.city}</h5>
                        </div>
                    </div>
                </div>
            </div>

        </div >
    )
}

export default OutputBox